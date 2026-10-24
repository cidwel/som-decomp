.setcpu "65816"
.segment "CODE"
.org $47E7
map_control_0e47e7:
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
