.setcpu "65816"
.segment "CODE"
.org $FF10
map_control_0eff10:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
