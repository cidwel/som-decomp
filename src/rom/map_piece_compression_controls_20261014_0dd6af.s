.setcpu "65816"
.segment "CODE"
.org $D6AF
map_control_0dd6af:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
