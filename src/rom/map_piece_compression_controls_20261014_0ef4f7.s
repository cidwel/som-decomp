.setcpu "65816"
.segment "CODE"
.org $F4F7
map_control_0ef4f7:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
