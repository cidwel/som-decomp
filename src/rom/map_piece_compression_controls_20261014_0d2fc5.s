.setcpu "65816"
.segment "CODE"
.org $2FC5
map_control_0d2fc5:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
