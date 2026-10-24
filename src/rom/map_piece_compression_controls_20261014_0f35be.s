.setcpu "65816"
.segment "CODE"
.org $35BE
map_control_0f35be:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
