//
// Created by alexmarino on 26/03/2020.
//

void shell_sort(int v[], int n) {
    int j, value;
    int x = 1;

    do {
        x = 3 * x + 1;
    } while (x < n);

    do {
        x /= 3;
        for (int i = x; i < n; i++) {
            value = v[i];
            j = i - x;

            while (j >= 0 && value < v[j]) {
                v[j + x] = v[j];
                j -= x;
            }
            v[j + x] = value;
        }
    } while (x > 1);
}


void select_sort(int vet[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (vet[j] < vet[min])
                min = j;
        }
        int temp = vet[min];
        vet[min] = vet[i];
        vet[i] = temp;
    }
}

void counting_sort2(int v[], int tamanho, int p) {
    int saida[tamanho];
    int x = (v[0] / p) % tamanho;
    for (int i = 1; i < tamanho; i++) {
        if (((v[i] / p) % tamanho) > x)
            x = v[i];
    }
    int contador[x + 1];
    for (int i = 0; i <= x; ++i) {
        contador[i] = 0;
    }
    for (int i = 0; i < tamanho; i++) {
        contador[(v[i] / p) % tamanho]++;
    }
    for (int i = 1; i <= x; i++) {
        contador[i] += contador[i - 1];
    }
    for (int i = tamanho - 1; i >= 0; i--) {
        saida[contador[v[i]] - 1] = v[i];
        contador[(v[i] / p) % tamanho]--;
    }
    for (int i = 0; i < tamanho; i++) {
        v[i] = saida[i];
    }
}


void counting_sort(int v[], int tamanho) {
    int saida[tamanho];

    int x = v[0];
    for (int i = 1; i < tamanho; i++) {
        if (v[i] > x)
            x = v[i];
    }
    int contador[tamanho];
    for (int i = 0; i <= x; ++i) {
        contador[i] = 0;
    }
    for (int i = 0; i < tamanho; i++) {
        contador[v[i]]++;
    }
    for (int i = 1; i <= x; i++) {
        contador[i] += contador[i - 1];
    }
    for (int i = tamanho - 1; i >= 0; i--) {
        saida[contador[v[i]] - 1] = v[i];
        contador[v[i]]--;
    }
    for (int i = 0; i < tamanho; i++) {
        v[i] = saida[i];
    }
}

int getMaximo(int v[], int n) {
    int maximo = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > maximo)
            maximo = v[i];
    return maximo;
}

void radix_sort(int v[], int tamanho) {
    int maximo = getMaximo(v, tamanho);

    for (int p = 1; maximo / p > 0; p *= tamanho)
        counting_sort2(v, tamanho, p);
}


void quick_sort(int v[], int p, int r) {


    int i = p;
    int j = r;
    int x = v[(p + r) / 2];

    while (i <= j) {
        while (v[i] < x && i < r) {
            i++;
        }
        while (v[j] > x && j > p) {
            j--;
        }
        if (i <= j) {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }

    if (j > p) {
        quick_sort(v, p, j);
    }
    if (i < r) {
        quick_sort(v, i, r);
    }
}

void intercalar(int v[], int x) {
    int q = x / 2;
    int i = 0;
    int j = q;
    int k = 0;
    int aux[x];

    while (i < q && j < x) {
        if (v[i] <= v[j]) {
            aux[k] = v[i++];
        } else {
            aux[k] = v[j++];
        }
        k++;
    }

    if (i == q) {
        while (j < x)
            aux[k++] = v[j++];
    } else {
        while (i < q) {
            aux[k++] = v[i++];
        }
    }
    for (i = 0; i < x; i++) {
        v[i] = aux[i];
    }
}

int merge_sort(int v[], int x) {
    int q = x / 2;

    if (x > 1) {
        merge_sort(v, q);
        merge_sort(v + q, x - q);
        intercalar(v, x);
    }

}

void insert_sort(int vet[], int n) {
    for (int i = 1; i < n; i++) {
        int x = vet[i];
        int j = i - 1;
        while (x < vet[j] && j >= 0) {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = x;
    }
}

void heap(int v[], int n, int i) {
    int maior = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && v[l] > v[maior])
        maior = l;

    if (r < n && v[r] > v[maior])
        maior = r;

    if (maior != i) {
        int temp = v[i];
        v[i] = v[maior];
        v[maior] = temp;
        heap(v, n, maior);
    }
}

void heap_sort(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(v, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;

        heap(v, i, 0);
    }
}


void bubble_sort(int v[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}


void bucket_sort(int v[], int tamanho) {
    int bucket[tamanho];
    const int maximo = getMaximo(v, tamanho);
    for (int i = 0; i <= maximo; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < tamanho; i++) {
        bucket[v[i]]++;
    }
    for (int i = 0, j = 0; i <= maximo; i++) {
        while (bucket[i] > 0) {
            v[j++] = i;
            bucket[i]--;
        }
    }
}
