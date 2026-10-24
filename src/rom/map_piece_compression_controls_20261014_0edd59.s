.setcpu "65816"
.segment "CODE"
.org $DD59
map_control_0edd59:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
