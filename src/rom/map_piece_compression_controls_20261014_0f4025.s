.setcpu "65816"
.segment "CODE"
.org $4025
map_control_0f4025:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
