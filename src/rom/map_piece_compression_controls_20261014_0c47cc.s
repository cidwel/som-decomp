.setcpu "65816"
.segment "CODE"
.org $47CC
map_control_0c47cc:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
