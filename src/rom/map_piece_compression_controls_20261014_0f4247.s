.setcpu "65816"
.segment "CODE"
.org $4247
map_control_0f4247:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
