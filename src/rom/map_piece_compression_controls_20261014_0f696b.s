.setcpu "65816"
.segment "CODE"
.org $696B
map_control_0f696b:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
