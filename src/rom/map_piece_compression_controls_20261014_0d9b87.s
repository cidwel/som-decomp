.setcpu "65816"
.segment "CODE"
.org $9B87
map_control_0d9b87:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
