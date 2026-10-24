.setcpu "65816"
.segment "CODE"
.org $F23B
map_control_0df23b:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
