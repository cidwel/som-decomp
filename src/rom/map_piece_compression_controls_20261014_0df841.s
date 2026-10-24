.setcpu "65816"
.segment "CODE"
.org $F841
map_control_0df841:
    .byte $F2 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
