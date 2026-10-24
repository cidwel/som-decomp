.setcpu "65816"
.segment "CODE"
.org $0FC1
map_control_0c0fc1:
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
