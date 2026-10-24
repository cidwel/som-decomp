.setcpu "65816"
.segment "CODE"
.org $682D
map_control_0f682d:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
