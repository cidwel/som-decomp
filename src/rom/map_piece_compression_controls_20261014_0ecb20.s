.setcpu "65816"
.segment "CODE"
.org $CB20
map_control_0ecb20:
    .byte $E4 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
