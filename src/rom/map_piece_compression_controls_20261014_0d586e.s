.setcpu "65816"
.segment "CODE"
.org $586E
map_control_0d586e:
    .byte $CA ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
