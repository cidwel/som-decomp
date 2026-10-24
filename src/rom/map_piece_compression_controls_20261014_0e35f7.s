.setcpu "65816"
.segment "CODE"
.org $35F7
map_control_0e35f7:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $0A ; distance low bit/count
