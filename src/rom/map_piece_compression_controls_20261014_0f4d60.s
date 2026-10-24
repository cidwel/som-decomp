.setcpu "65816"
.segment "CODE"
.org $4D60
map_control_0f4d60:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
