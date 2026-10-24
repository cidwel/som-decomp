.setcpu "65816"
.segment "CODE"
.org $DC52
map_control_0ddc52:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
