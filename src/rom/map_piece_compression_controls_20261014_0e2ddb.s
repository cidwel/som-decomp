.setcpu "65816"
.segment "CODE"
.org $2DDB
map_control_0e2ddb:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $CB ; same-value copy count/distance
