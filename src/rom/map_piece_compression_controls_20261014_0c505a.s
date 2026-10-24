.setcpu "65816"
.segment "CODE"
.org $505A
map_control_0c505a:
    .byte $EB ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $9D ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
