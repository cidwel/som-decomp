.setcpu "65816"
.segment "CODE"
.org $156B
map_control_0e156b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
