.setcpu "65816"
.segment "CODE"
.org $8CDB
map_control_0f8cdb:
    .byte $E7 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
