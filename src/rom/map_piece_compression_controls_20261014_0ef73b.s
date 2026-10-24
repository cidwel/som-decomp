.setcpu "65816"
.segment "CODE"
.org $F73B
map_control_0ef73b:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
