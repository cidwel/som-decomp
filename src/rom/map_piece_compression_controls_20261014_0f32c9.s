.setcpu "65816"
.segment "CODE"
.org $32C9
map_control_0f32c9:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $CA ; same-value copy count/distance
