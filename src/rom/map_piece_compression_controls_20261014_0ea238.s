.setcpu "65816"
.segment "CODE"
.org $A238
map_control_0ea238:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
