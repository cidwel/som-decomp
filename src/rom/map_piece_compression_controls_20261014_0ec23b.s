.setcpu "65816"
.segment "CODE"
.org $C23B
map_control_0ec23b:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
