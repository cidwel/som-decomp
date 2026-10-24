.setcpu "65816"
.segment "CODE"
.org $0E4B
map_control_0f0e4b:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
