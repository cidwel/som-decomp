.setcpu "65816"
.segment "CODE"
.org $A62F
map_control_0fa62f:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
