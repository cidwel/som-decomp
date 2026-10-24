.setcpu "65816"
.segment "CODE"
.org $131A
map_control_0e131a:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
