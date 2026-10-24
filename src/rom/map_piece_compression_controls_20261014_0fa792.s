.setcpu "65816"
.segment "CODE"
.org $A792
map_control_0fa792:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
