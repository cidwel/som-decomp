.setcpu "65816"
.segment "CODE"
.org $C03B
map_control_0fc03b:
    .byte $E4 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
