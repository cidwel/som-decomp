.setcpu "65816"
.segment "CODE"
.org $67DA
map_control_0c67da:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
