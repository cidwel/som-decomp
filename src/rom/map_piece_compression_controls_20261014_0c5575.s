.setcpu "65816"
.segment "CODE"
.org $5575
map_control_0c5575:
    .byte $D1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
