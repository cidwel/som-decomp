.setcpu "65816"
.segment "CODE"
.org $35CD
map_control_0f35cd:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
