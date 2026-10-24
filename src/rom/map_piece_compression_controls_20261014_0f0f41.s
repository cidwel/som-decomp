.setcpu "65816"
.segment "CODE"
.org $0F41
map_control_0f0f41:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
