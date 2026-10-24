.setcpu "65816"
.segment "CODE"
.org $93B7
map_control_0f93b7:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
