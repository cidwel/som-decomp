.setcpu "65816"
.segment "CODE"
.org $534C
map_control_0f534c:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
