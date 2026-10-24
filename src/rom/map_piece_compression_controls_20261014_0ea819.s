.setcpu "65816"
.segment "CODE"
.org $A819
map_control_0ea819:
    .byte $C9 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $31 ; distance low bit/count
