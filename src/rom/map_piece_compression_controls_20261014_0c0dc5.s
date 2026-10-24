.setcpu "65816"
.segment "CODE"
.org $0DC5
map_control_0c0dc5:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
