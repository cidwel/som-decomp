.setcpu "65816"
.segment "CODE"
.org $9200
map_control_0d9200:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
