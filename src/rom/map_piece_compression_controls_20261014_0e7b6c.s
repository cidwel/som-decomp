.setcpu "65816"
.segment "CODE"
.org $7B6C
map_control_0e7b6c:
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
