.setcpu "65816"
.segment "CODE"
.org $F75D
map_control_0ef75d:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
