.setcpu "65816"
.segment "CODE"
.org $93DF
map_control_0f93df:
    .byte $C6 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $0A ; distance low bit/count
