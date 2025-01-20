from collections import Counter

def contar_ids(arquivo):
    # Abrir o arquivo
    with open(arquivo, 'r') as f:
        # Ler todas as linhas
        linhas = f.readlines()

    # Extrair apenas os IDs da linha
    ids = [linha.split("->")[1].strip() for linha in linhas]

    # Contar a ocorrência de cada ID
    contagem = Counter(ids)

    # Exibir os resultados
    for id_, count in contagem.items():
        if count > 1:
            print(f"ID: {id_} - Encontrado {count} vez(es)")

# Usar a função passando o caminho do arquivo
contar_ids("data")  # Substitua pelo nome ou caminho correto do seu arquivo
