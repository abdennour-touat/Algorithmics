import pandas as pd
import plotly.express as px

df = pd.read_csv('resultat.csv')

fig = px.line(df, x = 'n', y = ['range_append','range_insert'], title='resultat range append)')
fig.show()
