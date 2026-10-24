.setcpu "65816"
.segment "CODE"
.org $7D5E
map_control_0f7d5e:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
