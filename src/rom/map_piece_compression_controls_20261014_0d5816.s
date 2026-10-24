.setcpu "65816"
.segment "CODE"
.org $5816
map_control_0d5816:
    .byte $C3 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $DC ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
