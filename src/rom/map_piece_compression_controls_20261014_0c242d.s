.setcpu "65816"
.segment "CODE"
.org $242D
map_control_0c242d:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
