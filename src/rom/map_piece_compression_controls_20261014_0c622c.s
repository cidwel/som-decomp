.setcpu "65816"
.segment "CODE"
.org $622C
map_control_0c622c:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
