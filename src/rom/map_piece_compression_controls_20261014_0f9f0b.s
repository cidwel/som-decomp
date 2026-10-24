.setcpu "65816"
.segment "CODE"
.org $9F0B
map_control_0f9f0b:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
