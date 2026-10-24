.setcpu "65816"
.segment "CODE"
.org $270E
map_control_0d270e:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
