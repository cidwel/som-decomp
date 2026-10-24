.setcpu "65816"
.segment "CODE"
.org $F6A1
map_control_0df6a1:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
