.setcpu "65816"
.segment "CODE"
.org $50C8
map_control_0c50c8:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D5 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
