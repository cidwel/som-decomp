.setcpu "65816"
.segment "CODE"
.org $35AD
map_control_0f35ad:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
